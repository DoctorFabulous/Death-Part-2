OBJ = main.o mytunes.o UI.o command.o str_util.o user.o users.o song.o songs.o recording.o recordings.o track.o tracks.o playlist.o

mytunes: $(OBJ)
	g++ -o mytunes $(OBJ)

main.o:	main.cpp 
	g++ -c main.cpp

mytunes.o:	mytunes.cpp mytunes.h UI.h
	g++ -c mytunes.cpp

UI.o:	UI.cpp UI.h 
	g++ -c -std=c++11 UI.cpp
	
command.o:	command.cpp command.h 
	g++ -c -std=c++11 command.cpp

str_util.o:	str_util.cpp str_util.h 
	g++ -c -std=c++11 str_util.cpp
	
user.o: user.cpp user.h
	g++ -c -std=c++11 user.cpp
	
users.o: users.cpp users.h
	g++ -c -std=c++11 users.cpp
	
song.o: song.cpp song.h
	g++ -c -std=c++11 song.cpp
	
songs.o: songs.cpp songs.h
	g++ -c -std=c++11 songs.cpp
	
recording.o: recording.cpp recording.h
	g++ -c -std=c++11 recording.cpp
	
recordings.o: recordings.cpp recordings.h
	g++ -c -std=c++11 recordings.cpp
	
track.o: track.cpp track.h
	g++ -c -std=c++11 track.cpp
	
tracks.o: tracks.cpp tracks.h
	g++ -c -std=c++11 tracks.cpp
	
playlist.o: playlist.cpp playlist.h
	g++ -c -std=c++11 playlist.cpp

clean:
	rm -f $(OBJ) mytunes
