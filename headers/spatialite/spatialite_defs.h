#ifndef SPATIALITE_DEFS
#define SPATIALITE_DEFS

/*
 ** CAPI3REF: Database Connection Handle
 ** KEYWORDS: {database connection} {database connections}
 **
 ** Each open SQLite database is represented by a pointer to an instance of
 ** the opaque structure named "sqlite3".  It is useful to think of an sqlite3
 ** pointer as an object.  The [sqlite3_open()], [sqlite3_open16()], and
 ** [sqlite3_open_v2()] interfaces are its constructors, and [sqlite3_close()]
 ** is its destructor.  There are many other interfaces (such as
 ** [sqlite3_prepare_v2()], [sqlite3_create_function()], and
 ** [sqlite3_busy_timeout()] to name but three) that are methods on an
 ** sqlite3 object.
 */
typedef struct sqlite3 sqlite3;

/*
 ** CAPI3REF: 64-Bit Integer Types
 ** KEYWORDS: sqlite_int64 sqlite_uint64
 **
 ** Because there is no cross-platform way to specify 64-bit integer types
 ** SQLite includes typedefs for 64-bit signed and unsigned integers.
 **
 ** The sqlite3_int64 and sqlite3_uint64 are the preferred type definitions.
 ** The sqlite_int64 and sqlite_uint64 types are supported for backwards
 ** compatibility only.
 **
 ** ^The sqlite3_int64 and sqlite_int64 types can store integer values
 ** between -9223372036854775808 and +9223372036854775807 inclusive.  ^The
 ** sqlite3_uint64 and sqlite_uint64 types can store integer values
 ** between 0 and +18446744073709551615 inclusive.
 */
#ifdef SQLITE_INT64_TYPE
typedef SQLITE_INT64_TYPE sqlite_int64;
typedef unsigned SQLITE_INT64_TYPE sqlite_uint64;
#elif defined(_MSC_VER) || defined(__BORLANDC__)
typedef __int64 sqlite_int64;
typedef unsigned __int64 sqlite_uint64;
#else
typedef long long int sqlite_int64;
typedef unsigned long long int sqlite_uint64;
#endif
typedef sqlite_int64 sqlite3_int64;
typedef sqlite_uint64 sqlite3_uint64;

#endif // SPATIALITE_DEFS
