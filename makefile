OBJECTS = deck.o card.o rank.o pokerhand.o SortedLinkedList.o
HEADERS = deck.h card.h rank.h pokerhand.h SortedLinkedList.h
CS216PA2: $(OBJECTS) PA2.o
	g++ $^ -o $@
testPA2: $(OBJECTS) testPA2.o
	g++ $^ -o $@
%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@
clean:
	rm -i *.o testPA2
