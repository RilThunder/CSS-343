Description 

The performance of a hash table depends critically on the quality of the hash function used. A poor hash function will result in many collisions (for open addressing) or long chains (for separate chaining). In general, hash functions are generated experimentally, based on the structure and statistics of the data to be stored. This exam asks you to develop a hash function for a separate chaining hash table. 

 

The file phonebook.txt contains 46,332 names and telephone numbers, one per line, with the name separated from the phone number by a tab character. Write a program that reads this file and stores its contents into a hash table with 4177 entries using separate chaining. You will use this program to investigate the performance of different hash functions.
