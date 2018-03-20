/* Stochastic Realizations */
	    case 'R': 
	      if(argv[argcount][2]=='0')
		sscanf(argv[argcount+1],"%d",&Realizations);
	      else if(argv[argcount][2]=='1')
		sscanf(argv[argcount+1],"%d",&DISCARTING_EXTINCTIONS);
              else exit(0);
	      skip++;
	      break;
	    
