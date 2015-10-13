from django.conf.urls import url, patterns, include
from django.conf.urls.static import static
from django.contrib.staticfiles.urls import staticfiles_urlpatterns
from finalProject import settings
# from polls import settings

from . import views

urlpatterns = [
	# url(r'^$', views.IndexView.as_view(), name='index'),
	url(r'^$', views.index, name='index'),
	url(r'^about$', views.about, name='about'),
	url(r'^home$', views.home, name='home'),
	url(r'^contact$', views.contact, name="contact"),
	url(r'^categories$', views.categories, name="categories"),
	url(r'^details$', views.details, name="details"),
	url(r'^details/(?P<itemId>[0-9]+)$', views.details, name="details"),
	url(r'^login$', views.login, name="login"),
	url(r'^checkout$', views.checkout, name="checkout"),
	url(r'^checkout/(?P<itemId>[0-9]+)$', views.checkout, name="checkout"),
	url(r'^checkout(?P<clear>true)$', views.checkout, name="checkout"),
	url(r'^account$', views.account, name='account'),
	url(r'^cart$', views.cart, name='cart'),
	url(r'^cart/(?P<itemId>[0-9]+)$', views.cart, name="cart"),
	url(r'^cart(?P<clear>true)$', views.cart, name="cart"),
	url(r'^index$', views.index, name='index'),

	# url(r'^static/(?P<path>.*)$', 'django.views.static.serve', {'document_root': settings.STATIC_ROOT}),
	
	# url(r'^(?P<pk>[0-9]+)/$', views.DetailView.as_view(), name="detail"),
	# url(r'^(?P<pk>[0-9]+)/results/$', views.ResultsView.as_view(), name='results'),
	# url(r'^(?P<question_id>[0-9]+)/vote/$', views.vote, name='vote'),
] + static(settings.MEDIA_URL, document_root=settings.MEDIA_ROOT)

urlpatterns += staticfiles_urlpatterns()

# urlpatterns = [
#     url(r'^$', views.IndexView.as_view(), name='index'),
#     url(r'^(?P<pk>[0-9]+)/$', views.DetailView.as_view(), name='detail'),
#     url(r'^(?P<pk>[0-9]+)/results/$', views.ResultsView.as_view(), name='results'),
#     url(r'^(?P<question_id>[0-9]+)/vote/$', views.vote, name='vote'),
# ]




# 	url(r'^$', views.index, name='index'),
# 	url(r'^(?P<question_id>[0-9]+)/$', views.detail, name='detail'),
# 	url(r'^(?P<question_id>[0-9]+)/results/$', views.results, name='results'),
# 	url(r'^(?P<question_id>[0-9]+)/vote/$', views.vote, name='vote'),
# ]