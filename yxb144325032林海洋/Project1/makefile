CC = clang -framework Foundation
DIR = cal
TARGET = cal
SOURCE = main.m Calendar.m 
build:
	cd $(DIR); $(CC) -o $(TARGET) $(SOURCE)
	mv $(DIR)/$(TARGET) .
	./$(TARGET)
	./$(TARGET) 10 2014
	./$(TARGET) -m 10
	./$(TARGET) 2014
clean:
	rm $(TARGET)