namespace std;

void F(int i)
{
  if (i%2)
    throw i;
  cout<<"Correct number"<<endl;
}

int main()
{
  try
  {
    for (int i=0; i<2; i++) 
    {
      F(i); cout<<"Next iteration"<<endl;
    }
  }
  catch(int i)
  {
    cout<<"Exception: "<<i<<endl; return i;
  }

  cout<<"Finished"<<endl;

  return 0;
}