#ifndef __UTILS_H__
#define __UTILS__H__

enum CharacterCaseType {
	CC_UPPER_CASE = 0,
	CC_LOWER_CASE,
	CC_EITHER,
};

char GetCharacter(const char* prompt, const char* error, CharacterCaseType characterCaseType);
char GetCharacter(const char* prompt, const char* error, const char validInput[], const int validInputLength, CharacterCaseType characterCaseType);

void ClearScreen();
void WaitForKeyPress();

#endif