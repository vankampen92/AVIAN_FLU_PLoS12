
	 case 'Y': 
	      if(argv[argcount][2]=='0')
		sscanf(argv[argcount+1],"%lf",&Fraction_S_0);
	      else if(argv[argcount][2]=='1')
		sscanf(argv[argcount+1],"%lf",&Fraction_I_0);
              else if(argv[argcount][2]=='2')
		sscanf(argv[argcount+1],"%lf",&Fraction_V_0);
              else {
		printf( "Only -Y0 -Y1 -Y2 are allowed\n"); 
		exit(0);
	      }
	      skip++;
	      break;
	    
