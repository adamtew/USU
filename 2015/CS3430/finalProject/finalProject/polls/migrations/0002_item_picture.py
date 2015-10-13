# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
        ('polls', '0001_initial'),
    ]

    operations = [
        migrations.AddField(
            model_name='item',
            name='picture',
            field=models.CharField(default='folder', max_length=50),
            preserve_default=False,
        ),
    ]
