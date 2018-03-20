/* Defintion of the grid  */ 
	    
	    case 'A': 
	      if(argv[argcount][2]=='0')
		sscanf(argv[argcount+1],"%lf",&Beta);
	      else if(argv[argcount][2]=='1'){
                if(argv[argcount][3]=='0'){
		  sscanf(argv[argcount+1],"%lf",&Rho);
		}
		else if(argv[argcount][3]=='1'){
		  sscanf(argv[argcount+1],"%lf",&Tau);
		}
		else {
		  sscanf(argv[argcount+1],"%lf",&Alpha);
		}
	      }
              else if(argv[argcount][2]=='2')
		sscanf(argv[argcount+1],"%lf",&Delta);
              else if(argv[argcount][2]=='3')
		sscanf(argv[argcount+1],"%lf",&Gamma);
              else if(argv[argcount][2]=='4')
		sscanf(argv[argcount+1],"%lf",&Mu);
              else if(argv[argcount][2]=='5')
		sscanf(argv[argcount+1],"%lf",&Imm_V);
              else if(argv[argcount][2]=='6')
		sscanf(argv[argcount+1],"%lf",&b_1);
              else if(argv[argcount][2]=='7')
		sscanf(argv[argcount+1],"%lf",&Per);
              else if(argv[argcount][2]=='8')
		sscanf(argv[argcount+1],"%lf",&Birth_V);
              else if(argv[argcount][2]=='9')
		sscanf(argv[argcount+1],"%lf",&Death_V);
              else {
		printf( "Only -A0 up to -A11 are allowed\n"); 
		exit(0);
	      }
	      skip++;
	      break;
	    
