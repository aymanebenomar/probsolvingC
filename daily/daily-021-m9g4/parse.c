// If value starts with the characters () { copy only the body between the
// braces into out and drop anything after the closing brace. Otherwise copy
// value unchanged. Null-terminate out.
void	parse_func_def(char *out, const char *value)
{
    int i, j;

    i = 0;
    j = 0;
    if (value[0] == '(' && value[1] == ')'
        && value[2] == ' ' && value[3] == '{')
    {
        i = 4;
        while(value[i] && value[i] != '}')
            out[j++] = value[i++];
    }
    else 
    {
        while(value[i])
            out[j++] = value[i++];
    }
    out[j] = '\0';
}
