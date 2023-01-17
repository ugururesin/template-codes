import sqlite3

# Connect to the database
cnx = sqlite3.connect('your_database.db')

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
