# non_truncate (PostgreSQL extension)

## What's this extension?
This extension disables the TRUNCATE statement by detecting the statement and raising ERROR.<br>
The error code is `ERRCODE_INVALID_SQL_StATEMENt_NAME`.

```sql
TRUNCATE sample_table;
ERROR:  non_truncate extension is banning TRUNCATE statement.
```

## Usage
You should 1) install this extension on your PostgreSQL and 1) enable this extension.<br>

1. Installing
You can install this extension with the following command in this repository's top-level directory.
```sh
make
make install
```

2. Enabling
You can enable this extension with the following statement:
```sql
CREATE EXTENSION non_truncate;
```
NOTE: This extension must be preloaded. Make sure that this extension is included in shared_preload_libraries in postgresql.conf.
