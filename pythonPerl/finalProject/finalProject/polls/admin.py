from django.contrib import admin

# from .models import Choice, Question, Item
from .models import Item, Category


# class ChoiceInline(admin.StackedInline):
# class ChoiceInline(admin.TabularInline):
#     model = Choice
#     extra = 3


class ItemAdmin(admin.ModelAdmin):
	model = Item
admin.site.register(Item, ItemAdmin)

class CategoryAdmin(admin.ModelAdmin):
	model = Category
admin.site.register(Category, CategoryAdmin)




# class QuestionAdmin(admin.ModelAdmin):
#     fieldsets = [
#         (None,               {'fields': ['question_text']}),
#         ('Date information', {'fields': ['pub_date'], 'classes': ['collapse']}),
#     ]
#     inlines = [ChoiceInline]
#     list_display = ('question_text', 'pub_date', 'was_published_recently');
#     list_filter = ['pub_date']

# admin.site.register(Question, QuestionAdmin)




# admin.site.register(Item, ItemAdmin)