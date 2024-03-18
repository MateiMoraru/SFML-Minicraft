all:
	g++ main.cpp chunk.cpp block.cpp environment.cpp tree.cpp game_object.cpp -o a.out -lsfml-graphics -lsfml-window -lsfml-system
