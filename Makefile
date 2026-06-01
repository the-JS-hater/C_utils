test_arr: test_arr.c d_array.c d_array.h
	gcc test_arr.c d_array.c d_array.h -o test
	./test

test_bitset: test_bitset.c bitset.c bitset.h
	gcc test_bitset.c bitset.c bitset.h -o test
	./test

test_hashtable: test_hashtable.c hashtable.c hashtable.h
	gcc test_hashtable.c hashtable.c hashtable.h -o test
	./test
