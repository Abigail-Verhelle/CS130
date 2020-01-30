for(int j = 0; j < p; j++)
{
    lowest = b[j];
    for (int i = j; i < p; i++)
    {
        if (b[i] < lowest)
        {
            lowest = b[i];
            index = i;
        }
    }
    //tostring(b[i])
    finalArray[j] = b[i] + " " + a[i];
}
