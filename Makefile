MODULES = non_truncate
EXTENSION = non_truncate
REGRESS = non_truncate
DATA = non_truncate--1.0.sql
PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)

