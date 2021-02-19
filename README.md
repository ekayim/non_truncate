# non_truncate (PostgreSQL extension)

## What's this extension?
This extension disables the TRUNCATE statement by detecting the statement and raising ERROR.<br>
The error code is `ERRCODE_INVALID_SQL_StATEMENt_NAME`.

```sql
TRUNCATE sample_table;
ERROR:  non_truncate extension is banning TRUNCATE statement.
```

## Install
You can install this extension with the following command in this repository's top-level directory.
```sh
$ make
$ make install
```

## Note
This extension must be preloaded. 
Make sure that this extension is included in shared_preload_libraries in postgresql.conf.
