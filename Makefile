
all: Type_signal_info

signal-echo: Type_signal_info.o
  g++ -o Type_signal_info Type_signal_info.o

signal-echo.o: Type_signal_info.cpp
  g++ -c Type_signal_info.cpp  

clean:
  rm -f Type_signal_info.o Type_signal_info
