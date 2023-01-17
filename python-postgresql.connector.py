import psycopg2

# Connect to the database
cnx = psycopg2.connect(user='your_username',
                      password='your_password',
                      host='your_host',
                      database='your_database')

# Create a cursor object
cursor = cnx.cursor()

# Execute a query
cursor.execute("SELECT * FROM your_table")

# Fetch results
results = cursor.fetchall()

# Iterate over the results and print each row
for row in results:
    print(row)

# Close the cursor and connection
cursor.close()
cnx.close()
