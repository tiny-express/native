from filewatch import ObserverBase, file_updated_subject, Watcher

class YourObserver(ObserverBase):
    def notify(self, *args, **kwargs):
        file_list = kwargs['file_list']
        print 'These files have been updated %s' % file_list

file_updated_subject.register_observer(YourObserver())
watcher = Watcher()
watcher.run()