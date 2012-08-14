from time import time
from math import floor, fmod
from hashlib import sha1
from base64 import b32decode
from struct import pack, unpack_from
import gconf
import hmac

secret = b32decode('yalbxtsy65brdxoy', True)
now = time()
now = int(floor( now / 30 ))

# The value is an 8-byte big endian (Java) interval number
value = pack("!q", now)

# The hashing algorithm is HMACSHA1
hm = hmac.new(secret, value, sha1)

# Get the resulting binary digest
digest = hm.digest()

# Truncate the hash
offset = unpack_from("b", digest[-1])[0] & 0xf
temp_pin = (unpack_from("!i", digest, offset)[0] & 0x7FFFFFFF) % 10**6
pin = str(temp_pin).zfill(6)
print pin

