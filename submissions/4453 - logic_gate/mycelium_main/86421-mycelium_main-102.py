# Set — fast membership check
seen = set()
seen.add(5)
if 5 in seen: print('found')
# Remove duplicates from list
unique = list(set(nums))
# Dictionary
d = {}
d['key'] = 10
d.get('key', 0) # get with default
d.keys() # all keys
d.values() # all values
for k, v in d.items(): # loop key-value
 print(k, v)