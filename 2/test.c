void main()
{
  char a[10],b[10];
  int i=0,j;
  printf("\n enter your word::");
  scanf("%s",a);
  while(a[i])
  {
   putchar(tolower(a[i]));
   i++;
  }
  j=strlen(a);
  for(i=0;i<j;i++)
  {
    b[i]=a[j-i-1];
  }
  b[i]='\0';
   int flag=0;
  for(i=0;i<j;i++)
  {
   if(a[i]!=b[i])
   flag=1;
  }
  if(flag)
  printf("\nnot a palindrome\n");
  else
  printf("\npalindrome\n");
}