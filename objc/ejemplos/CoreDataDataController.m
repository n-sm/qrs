@interface MyDataController : NSObject
     
@property (strong) NSManagedObjectContext *managedObjectContext;
     
- (void)initializeCoreData;
     
@end
     
@implementation MyDataController
     
- (id)init
{
  self = [super init];
  if (!self) return nil;
     
  [self initializeCoreData];
     
  return self;
}
     
- (void)initializeCoreData
{
  NSURL *modelURL = [[NSBundle mainBundle] URLForResource:@"DataModel" withExtension:@"momd"];
  NSManagedObjectModel *mom = [[NSManagedObjectModel alloc] initWIthContentsOfURL:modelURL];
  NSAssert(mom != nil, @"Error initializing Managed Object Model");
     
  NSPersistentStoreCoordinator *psc = [[NSPersistentStoreCoordinator alloc] initWithManagedObjectModel:mom];
  NSManagedObjectContext *moc = [[NSManagedObjectContext alloc] initWithConcurrencyType:NSMainQueueConcurrencyType];
  [moc setPersistentStoreCoordinator:psc];
  [self setManagedObjectContext:moc];
  NSFileManageer *fileManager = [NSFileManager defaultManager];
  NSURL *documentsURL = [[fileManager URLsForDirectory:NSDocumentDirectory inDomains:NSUserDomainMask] lastObject];
  NSURL *storeURL = [documentsURL URLByAppendingPathComponent:@"DataModel.sqlite"];
     
  dispatch_async(dispatch_get_global_queue( DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^(void) {
      NSError *error = nil;
      NSPersistentStoreCoordinator *psc = [[self managedObjectContext] persistentStoreCoordinator];
      NSPersistentStore *store = [psc addPersistentStoreWithType:NSSQLiteStoreType configuration:nil URL:storeURL options:options error:&error];
      NSAssert(store != nil, @"Error initializing PSC: %@\n%@", [error localizedDescription], [error userInfo]);
    });
}

