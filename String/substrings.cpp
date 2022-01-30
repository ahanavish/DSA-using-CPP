void print(string str)
{
    int n = str.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j <= n - i; ++j)
        {
            string sub = str.substr(i, j);
            cout << i << j << sub << " ";
        }
    }
}