// Replace ${user} with "neo" and ${env} with "prod". Leave any other ${...}
// exactly as written. Single pass: never re-expand a substituted value.
// Null-terminate out.
void	expand(char *out, const char *tmpl)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while(tmpl[i])
    {
        if(tmpl[i] == '$'
            && tmpl[i + 1] == '{'
            && tmpl[i + 2] == 'u'
            && tmpl[i + 3] == 's'
            && tmpl[i + 4] == 'e'
            && tmpl[i + 5] == 'r'
            && tmpl[i + 6] == '}')
        {
            out[j++] = 'n';
            out[j++] = 'e';
            out[j++] = 'o';
            i += 7;
        }
        else if (tmpl[i] == '$'
            && tmpl[i + 1] == '{'
            && tmpl[i + 2] == 'e'
            && tmpl[i + 3] == 'n'
            && tmpl[i + 4] == 'v'
            && tmpl[i + 5] == '}')
        {
            out[j++] = 'p';
            out[j++] = 'r';
            out[j++] = 'o';
            out[j++] = 'd';
            i += 6;
        }
        else 
        {
            out[j] = tmpl[i];
            j++;
            i++;
        }
    }
    out[j] = '\0';
}
