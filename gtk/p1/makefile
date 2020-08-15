TARGET := p1
CFLAGS := `pkg-config --cflags --libs gtk+-3.0` 

$(TARGET) : p1.c
	gcc $< -o $(TARGET) $(CFLAGS)
