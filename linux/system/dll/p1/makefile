TARGET := p1
TARGET_LIB := lib.so
TOTAL :=


$(TARGET) : main.c $(TARGET_LIB)
	gcc main.c -o $(TARGET)	-fPIC -rdynamic -ldl
	

$(TARGET_LIB) : lib/lib.c
	gcc lib/lib.c -o lib/$(TARGET_LIB) -shared -fPIC -rdynamic
	
