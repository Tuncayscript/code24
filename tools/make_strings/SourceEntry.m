#include <Foundation/NSObject.h>
#include <Foundation/NSString.h>

#include "SourceEntry.h"

@implementation SourceEntry

- initWithKey: (NSString *)k comment: (NSString *)c file: (NSString *)f
	 line: (unsigned int)l
{
  self=[super init];

  ASSIGN(file,f);
  ASSIGN(comment,c);
  ASSIGN(key,k);
  line=l;
  return self;
}

-(void) dealloc
{
  DESTROY(file);
  DESTROY(comment);
  DESTROY(key);
  [super dealloc];
}


-(NSString *) description
{
  return [NSString
	   stringWithFormat: @"(key='%@' comment='%@'  at '%@':%i)",
	   key,comment,file,line];
}


-(NSString *) file { return file; }
-(NSString *) comment { return comment; }
-(NSString *) key { return key; }
-(unsigned int) line { return line; }

@end
