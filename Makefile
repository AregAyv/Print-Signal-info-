all: Type_signal_info.cpp

Type_signal_info.cpp: Type_signal_info.cpp
	g++ -o Type_signal_info.cpp Type_signal_info.cpp

clean:
       rm -f Type_signal_info.cpp
