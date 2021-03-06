#include <stdlib.h>
#include <stdio.h>
#include <sqlite3.h> 

static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)data);
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int main(int argc, char* argv[])
{
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;
   const char* data = "Callback function called";
int load;bool dv;
load = atoi(argv[1]);
dv = atoi(argv[2]);

   /* Open database */
   rc = sqlite3_open("/var/Keychains/keychain-2.db", &db);
   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
   }else{
      fprintf(stderr, "Opened database successfully\n");
   }

   /* Create SQL statement */
if(!dv){
	if(load==1){
	sql = "UPDATE genp SET agrp = '6WX5RKLG95.com.supercell.magic1' WHERE agrp = '6WX5RKLG95.com.supercell.magic'";
	fprintf(stdout,"[ + ] save #1\n");}
	else if(load==2)
	{//sql = "delete from genp where agrp = '6WX5RKLG95.com.supercell.magic'";
	sql = "UPDATE genp SET agrp = '6WX5RKLG95.com.supercell.magic2' WHERE agrp = '6WX5RKLG95.com.supercell.magic';";
//"UPDATE genp SET agrp = '6WX5RKLG95.com.supercell.magic' WHERE agrp = '6WX5RKLG95.com.supercell.magic1';";
	fprintf(stdout,"[ + ] save #2\n");}else if(load ==11){
sql= "UPDATE genp SET agrp = '6WX5RKLG95.com.supercell.magic' WHERE agrp = '6WX5RKLG95.com.supercell.magic1'";fprintf(stdout,"[ + ] load #1\n");}else if(load ==12){
sql= "UPDATE genp SET agrp = '6WX5RKLG95.com.supercell.magic' WHERE agrp = '6WX5RKLG95.com.supercell.magic2'";fprintf(stdout,"[ + ] load #2\n");}}
else
{
sql="DELETE FROM genp WHERE agrp LIKE '%6WX5RKLG95.com.supercell.magic%';";
fprintf(stdout,"[ + ] delete\n");
}
   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Operation done successfully\n");
   }
   sqlite3_close(db);
   return 0;
} 
