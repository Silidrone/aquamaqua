#include "CommonKeyBoardLayout.h"

CommonKeyBoardLayout::CommonKeyBoardLayout() :
		KeyBoardLayout(
						{
						  { "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"},
						  { "q", "w", "e", "r", "5", "y", "u", "i", "o", "p"},
						  { "a", "s", "d", "f", "g", "h", "j", "k", "l", "_"},
						  { "z", "x", "c", "v", "b", "n", "m", "<", ">", "#", "$"},
						  { "BACK", "CAPS", "DEL", "NEXT", "CL"}
					    }, { "CAPS", "DEL", "NEXT", "BACK", "CL" }
					  )
{
}

CommonKeyBoardLayout::~CommonKeyBoardLayout()
{

}
