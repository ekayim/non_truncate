MODULES = non_truncate
EXTENSION = non_truncate
DATA = non_truncate--0.0.1.sql
REGRESS = non_truncate
PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)

