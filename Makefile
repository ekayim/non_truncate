MODULES = non_truncate
EXTENSION = non_truncate
REGRESS = non_truncate
PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)

