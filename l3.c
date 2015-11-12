int main()
{
  int a=12;
jump1:
  a=a%2;
  goto jump1;
  
  switch(a)
  {
    case 1:
      a=a+1, c=13;
      break;
    case 2:
      a=a-1;
      break;
    case 3:
      a=a*2;
      break;
      return ;
    default:
      break;
  }
  continue;
  return 0;
}
