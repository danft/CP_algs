#http://bit.do/danft

if ! [ -a "$HOME/.vimrc" ]
then
	wget tiny.cc/danft2 -O "$HOME/.vimrc" &> /dev/null
fi
if ! [ -a "$HOME/te.cpp" ]
then
	wget tiny.cc/danft2 -O "$HOME/te.cpp" &> /dev/null
fi

setxkbmap -layout "us"

echo "export CXXFLAGS=-std=c++0x" >> "$HOME/.bashrc"
