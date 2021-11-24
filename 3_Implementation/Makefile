SRC = Tictac.c\
src/Tictac.c
INC = inc
Tictac.exe : $(SRC) 
    gcc $^ -I$(INC) -o $@

run : Tictac.exe
    ./TictacTictac.exe

clean:
    del Tictac.exe
