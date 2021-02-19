# non_truncate (PostgreSQL extension)

## Test status
[![build](https://github.com/ekayim/non_truncate/actions/workflows/build.yml/badge.svg)](https://github.com/ekayim/non_truncate/actions/workflows/build.yml)

## What's this extension?
This extension disables the TRUNCATE statement by detecting the statement and raising ERROR.<br>
The error code is `ERRCODE_INVALID_SQL_StATEMENt_NAME`.
This extension requires PostgreSQL 13 or later.

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
