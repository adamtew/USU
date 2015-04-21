# this information can be found in more detail at
# https://docs.djangoproject.com/en/1.7/intro/tutorial01/

Important django commands

import django
# this imports the django utilities

from django.db import models
# this imports the models from the database class

python -c "import django; print(django.get_version())"
# this lets you know if you've got django installed on your machine

python django-admin.py startproject mysite
# this command starts a site for you by creating the appropriate file structure

python manage.py migrate 
# looks into your move all of your apps INSTALLED_APPS in the project/settings.py 
# and sets up database information for all of them

python manage.py runserver 
# starts your django server, this can be accessed at 127.0.0.1:8000
#additionally, you can change the port by running python manage.py runserver 8080

python manage.py startapp myapp
# this command starts an app for you by creating the appropriate file structure

# myapp/models.py is where you add db (model) information
# it's important to put your app name in the INSTALLED_APPS section of the project/settings.py file

python manage.py makemigrations myapp
# this command 'tells django you've made changes to your models and you'd like to store
# those changes as a migration'

python manage.py sqlmigrate myapp 0001
# this command migrates the sql information from your migrations to your db?

python manage.py check
# this checks for any problems in your project without making migrations or touching
# the database

python manage.py shell
# this opens an interactive shell to work with django

