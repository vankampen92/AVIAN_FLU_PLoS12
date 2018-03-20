/* Parameter Space */ 
	    
	    case 'P': 
	      if(argv[argcount][2]=='0')
		sscanf(argv[argcount+1],"%d",&SUB_MODEL_PARAMETERS);
	      else if(argv[argcount][2]=='1')
	      	sscanf(argv[argcount+1],"%lf",&A_n);
              else if(argv[argcount][2]=='2')
	      	sscanf(argv[argcount+1],"%lf",&A_d);
              else exit(0);
	      skip++;
	      break;
	    
