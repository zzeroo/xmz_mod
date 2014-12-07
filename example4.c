/** make with
 * gcc -o example4 example4.c $(pkg-config --cflags --libs libmongoc-1.0)
 */
#include <bcon.h>
#include <bson.h>
#include <mongoc.h>
#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
    mongoc_collection_t *collection;
    mongoc_client_t *client;
    bson_error_t error;
    bson_oid_t oid;
    bson_t *doc = NULL;
    bson_t *update = NULL;
    bson_t *query = NULL;
    int i;

    mongoc_init ();

    client = mongoc_client_new ("mongodb://localhost:3001/");
    collection = mongoc_client_get_collection (client, "meteor", "sensors");


    query = bson_new ();
    BSON_APPEND_UTF8 (query, "name", "Sensor 1");

    for (i = 0; i < 101; i++) {
      update = BCON_NEW ("$set", "{",
                             "value", BCON_INT32 (i),
                         "}");

      if (!mongoc_collection_update (collection, MONGOC_UPDATE_NONE, query, update, NULL, &error)) {
          printf ("%s\n", error.message);
          goto fail;
      }
      sleep(1);
    }

    query = bson_new ();
    BSON_APPEND_UTF8 (query, "name", "Sensor 2");

    for (i = 0; i < 101; i++) {
      update = BCON_NEW ("$set", "{",
                             "value", BCON_INT32 (i),
                         "}");

      if (!mongoc_collection_update (collection, MONGOC_UPDATE_NONE, query, update, NULL, &error)) {
          printf ("%s\n", error.message);
          goto fail;
      }
      sleep(1);
    }

fail:
    if (doc)
        bson_destroy (doc);
    if (query)
        bson_destroy (query);
    if (update)
        bson_destroy (update);

    mongoc_collection_destroy (collection);
    mongoc_client_destroy (client);

    return 0;
}
