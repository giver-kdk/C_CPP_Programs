printf("\t\t          Name             ");puts(elem[i].name);printf("\n");
printf("\t\t                Origin of Name       ");printf("\n\t\t");puts(elem[i].origin);printf("\n");
printf("\t\t       Atomic Number       "<<elem[i].atomicno<<"\n";
printf("\t\t Electronic Configuration  ";puts(elem[i].ec);
printf("\t\t         Group             "<<elem[i].group<<"\n";
printf("\t\t         Period            "<<elem[i].period<<"\n";
printf("\t\t         Block             "<<elem[i].block<<"\n";
printf("\t\t      Atomic Weight        "<<elem[i].atomicw<<"\n";
if(elem[i].atomicr==0)
{printf("\t\t      Atomic Radius        "<<"Not Available"<<"\n";}
else
{printf("\t\t      Atomic Radius        "<<elem[i].atomicr<<" pm"<<"\n";}
if(elem[i].en==0)
{printf("\t\t    Electronegativity      "<<"Not Available"<<"\n";}
else
{printf("\t\t    Electronegativity      "<<elem[i].en<<" (Pauling Scale)"<<"\n";}
if(elem[i].meltp==0)
{printf("\t\t       Melting Point       "<<"Not Available"<<"\n";}
else
{printf("\t\t       Melting Point       "<<elem[i].meltp<<" K"<<"\n";}
if(elem[i].boilp==0)
{printf("\t\t       Boiling Point       "<<"Not Available"<<"\n";}
else
{printf("\t\t       Boiling Point       "<<elem[i].boilp<<" K"<<"\n";}
if(elem[i].density==0)
{printf("\t\t         Density           "<<"Not Available"<<"\n";}
else
{printf("\t\t         Density           "<<elem[i].density<<" g/cm3"<<"\n";}
goto end;