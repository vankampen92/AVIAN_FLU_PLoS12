	    
	    case 'C': 
	      if(argv[argcount][2]=='0')
		sscanf(argv[argcount+1],"%d",&N);
	      else if(argv[argcount][2]=='1')
		sscanf(argv[argcount+1],"%d",&POPULATION);
              else if(argv[argcount][2]=='2')
		sscanf(argv[argcount+1],"%d",&no_Patch);
              else if(argv[argcount][2]=='3')
		sscanf(argv[argcount+1],"%d",&N_V);
              else exit(0);
	      skip++;
	      break;
	    
   /* Number of variables needed to describe the state
		         of the system at any given time */
