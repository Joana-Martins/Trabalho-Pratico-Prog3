  
CC=g++
CXXFLAGS= -g -std=c++17
DEPS = album.h artista.h assinante.h midia.h musica.h plataformadigital.h podcast.h podcaster.h produtor.h usuario.h
OBJ = album.o artista.o assinante.o midia.o musica.o plataformadigital.o podcast.o podcaster.o produtor.o usuario.o index.o
%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CXXFLAGS)

index: $(OBJ)
	$(CC) -o $@ $^ $(CXXLAGS)

clean:
	rm -f *.o
	rm index