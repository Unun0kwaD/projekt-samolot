LIBS=-lGL -lglfw -lGLEW -lassimp
HEADERS=constants.h constants.h shader.h object_vertices.h Model.h skybox.h collisions.h glad/glad.h stb_image.h lights.h readtexture.h plane.h

FILES= main_file.cpp skybox.cpp stb_image.cpp glad/glad.c lights.cpp buildings.cpp object_vertices.cpp readtexture.cpp plane.cpp collision.cpp Model.cpp
TARGET=main

main_file: $(FILES) $(HEADERS)
	g++ -o $(TARGET) $(FILES)  $(LIBS) -I.

clean:
	rm -f $(TARGET)

run:
	./$(TARGET)