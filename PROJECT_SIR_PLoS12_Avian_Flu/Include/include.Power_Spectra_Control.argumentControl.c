/* Time Control Definition */ 
	   
	    case 'D': 
	      if(argv[argcount][2]=='0')
		sscanf(argv[argcount+1],"%d", &PSD_TIMES);
              else if(argv[argcount][2]=='1')
		sscanf(argv[argcount+1],"%d", &TRANSIENT);
              else if(argv[argcount][2]=='2')
		sscanf(argv[argcount+1],"%d", &k_Sets);
              else if(argv[argcount][2]=='3')
		sscanf(argv[argcount+1],"%lf",&STEP_SIZE);
              else{ 
		printf(" Only -D0 [] -D1 [] -D2 [] -D3 [] are allowed\n");
		exit(0);
	      }
              skip++;
	      break;
	    
            
	    
	    
