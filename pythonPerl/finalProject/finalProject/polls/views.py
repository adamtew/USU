from django.shortcuts import render, get_object_or_404

# Create your views here.
from django.http import HttpResponseRedirect, HttpResponse
from django.core.urlresolvers import reverse
from django.views import generic
from itertools import chain

# from .models import Question
from .models import Item, Category


# for debugging
# import pdb; pdb.set_trace()

def index(request):
	return render(request, 'index.html');

def home(request):
	return render(request, 'home.html');

def about(request):
	return render(request, 'about.html');

def contact(request):
	return render(request, 'contact.html');

def categories(request):
	name = "Adam";
	c = Category.objects.all();
	i = Item.objects.all();
	myVars = []
	for x in c:
		myVars.append({"Category": x, "Items": i.filter(category=x)})
	context = {'pageVars': myVars}
	return render(request, 'categories.html', context);

def details(request, itemId=0):
	if 'purchase' in request.GET:
		item = Item.objects.filter(id=itemId);
		makeCart(request, item[0]);		

	# request.session.clear();
	i = Item.objects.filter(id=itemId);
	context = {'item': i[0]};
	request.session.name = "Adam";
	# import pdb; pdb.set_trace()

	return render(request, 'details.html', context);

def login(request):
	return render(request, 'login.html');

def checkout(request):
	return render(request, 'checkout.html');

def makeCart(myRequest, value):
	if 'cart' in myRequest.session:
		temp = myRequest.session['cart'];
		temp.append(value);
		myRequest.session['cart'] = temp;
	else:
		temp = [];
		temp.append(value);
		myRequest.session['cart'] = temp;

# class IndexView(generic.ListView):
# 	template_name = 'polls/index.html'

	# def get_queryset(self):
	# 	"""return some items from a query"""
	# 	return Category.objects.all();

# class DetailView(generic.ListView):
# 	template_name = 'polls/detail.html'


# class IndexView(generic.ListView):
# 	template_name = 'polls/index.html'
# 	context_object_name = 'latest_question_list'

# 	def get_queryset(self):
# 		"""Return the last five published questions."""
# 		return Question.objects.order_by('-pub_date')[:5]

# class DetailView(generic.DetailView):
# 	model = Question
# 	template_name = 'polls/detail.html'

# class ResultsView(generic.DetailView):
# 	model = Question
# 	template_name = 'polls/results.html'

# def vote(request, question_id):
# 	p = get_object_or_404(Question, pk=question_id)
# 	try:
# 		selected_choice = p.choice_set.get(pk=request.POST['choice'])
# 	except (KeyError, Choice.DoesNotExist):
# 		return render(request, 'polls/details.html', {
# 			'question': p,
# 			'error_message': "You didn't select a choice.",
# 		})
# 	else:
# 		selected_choice.votes += 1
# 		selected_choice.save()

# 	return HttpResponseRedirect(reverse('polls:results', args=(p.id,)))
	# return HttpResponse("You're voting on question %s." % question_id);









# def index(request):
# 	latest_question_list = Question.objects.order_by('-pub_date')[:5]
# 	context = {'latest_question_list': latest_question_list};
# 	return render(request, 'polls/index.html', context);

# def detail(request, question_id):
# 	question = get_object_or_404(Question, pk=question_id);
# 	return render(request, 'polls/detail.html', {'question': question});

# def results(request, question_id):
#     question = get_object_or_404(Question, pk=question_id)
#     return render(request, 'polls/results.html', {'question': question})
