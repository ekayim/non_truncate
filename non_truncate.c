#include "postgres.h"
#include "fmgr.h"
#include "tcop/utility.h"

PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(addme);

void		_PG_init(void);
void		_PG_fini(void);
static ProcessUtility_hook_type prev_ProcessUtility = NULL;
static void nt_ProcessUtility(PlannedStmt *pstmt, const char *queryString,
								ProcessUtilityContext context, ParamListInfo params,
								QueryEnvironment *queryEnv,
								DestReceiver *dest, QueryCompletion *qc);

void
_PG_init(void)
{
	prev_ProcessUtility = ProcessUtility_hook;
	ProcessUtility_hook = nt_ProcessUtility;
}

void
_PG_fini(void)
{
	/* Uninstall hooks. */
	ProcessUtility_hook = prev_ProcessUtility;
}

/*
 * ProcessUtility hook
 */
static void
nt_ProcessUtility(PlannedStmt *pstmt, const char *queryString,
					ProcessUtilityContext context,
					ParamListInfo params, QueryEnvironment *queryEnv,
					DestReceiver *dest, QueryCompletion *qc)
{
	if (pstmt->utilityStmt->type == T_TruncateStmt){
		ereport(ERROR,
				(errcode(ERRCODE_INVALID_SQL_STATEMENT_NAME),
				 errmsg("non_truncate extension is banning TRUNCATE statement.")));
		}

	if (prev_ProcessUtility)
		prev_ProcessUtility(pstmt, queryString,
				context, params, queryEnv,
				dest, qc);
	else
		standard_ProcessUtility(pstmt, queryString,
					context, params, queryEnv,
					dest, qc);
}
