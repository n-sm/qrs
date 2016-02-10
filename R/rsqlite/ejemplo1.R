
if (require("RSQLite")) {
    con <- dbConnect(RSQLite::SQLite(), ":memory:")

    dbWriteTable(con, "mtcars", mtcars)
    res <- dbSendQuery(con, "SELECT * FROM mtcars WHERE cyl = 4;")
    dbFetch(res)
    dbClearResult(res)

    dbDisconnect(con)
}

