/** compile so
 * gcc -o example1 example1.c $(pkg-config --cflags --libs libmongoc-1.0)
 *
 * Einfacher Test der Verbindung zur Meteor MongoDB.
 * Die URL kann mit `meteor mongo --url` ausfindig gemacht werden.
 */
#include <bson.h>
#include <mongoc.h>
#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
    mongoc_client_t *client;
    mongoc_collection_t *collection;
    mongoc_cursor_t *cursor;
    const bson_t *doc;
    bson_t *query;
    char *str;

    mongoc_init ();

    client = mongoc_client_new ("mongodb://localhost:3001/");
    collection = mongoc_client_get_collection (client, "meteor", "sensors");
    query = bson_new ();
    cursor = mongoc_collection_find (collection, MONGOC_QUERY_NONE, 0, 0, 0, query, NULL, NULL);

    while (mongoc_cursor_next (cursor, &doc)) {
        str = bson_as_json (doc, NULL);
        printf ("%s\n", str);
        bson_free (str);
    }

    bson_destroy (query);
    mongoc_cursor_destroy (cursor);
    mongoc_collection_destroy (collection);
    mongoc_client_destroy (client);

    return 0;
}
