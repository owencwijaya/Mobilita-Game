/**
 * @deprecated 
 * @brief This function is no longer used, use the
 *        combination of stringify and isStringEquals
 *        instead.
 * @see "./modules/io/word_utils.c"
 */

boolean checkWord(Word currentWord, char s[])
{
    int count = 0;
    ;
    int i = 0;

    while (s[count] != '.')
    {
        count++;
    }

    Word temp;
    temp.length = count;

    for (i = 0; i < count; i++)
    {
        temp.contents[i] = s[i];
    }

    boolean isEqual = false;
    i = 0;
    if (currentWord.length == temp.length)
    {
        isEqual = true;
        while (i < temp.length && isEqual)
        {
            if (currentWord.contents[i] != temp.contents[i])
            {
                isEqual = false;
            }
            i++;
        }
    }
    return isEqual;
}
