Gitbro::Application.routes.draw do
  get 'new_page' => 'posts#new'
  match 'posts/create' => 'posts#create'
  get 'posts/:page_name'  => 'posts#show'
  match 'posts/:page_name/update'  => 'posts#update'
  get 'posts/:page_name/edit'  => 'posts#edit'
  get "log_in" => "sessions#new", :as => "log_in"  # if you use "peters/new" rather than "peters#new", error: peters uninitilized
  # post "log_in" => "peter#new", :as => "log_in"  
  # if you use POST to sent '/login', you need the above line, otherwise you
  # get a strange error: No route matches "/log_in"
  get "log_out" => "sessions#destroy", :as => "log_out"  

  get "sign_up" => "users#new", :as => "sign_up"  
  get "posts" => "posts#index" #peter added this foolishly
  root :to => "posts#index"  
  
  get ':name' => 'posts#index', :as => 'user_posts'
  # because this line all my restful defualts won't work any more, how to fix?
  # from now on every thing after 3000/xxx will be params[:name]
  # so never put this before the above several lines

  resources :users do
    resources :posts
  end

  resources :sessions
  # The priority is based upon order of creation:
  # first created -> highest priority.

  # Sample of regular route:
  #   match 'products/:id' => 'catalog#view'
  # Keep in mind you can assign values other than :controller and :action

  # Sample of named route:
  #   match 'products/:id/purchase' => 'catalog#purchase', :as => :purchase
  # This route can be invoked with purchase_url(:id => product.id)

  # Sample resource route (maps HTTP verbs to controller actions automatically):
  #   resources :products

  # Sample resource route with options:
  #   resources :products do
  #     member do
  #       get 'short'
  #       post 'toggle'
  #     end
  #
  #     collection do
  #       get 'sold'
  #     end
  #   end

  # Sample resource route with sub-resources:
  #   resources :products do
  #     resources :comments, :sales
  #     resource :seller
  #   end

  # Sample resource route with more complex sub-resources
  #   resources :products do
  #     resources :comments
  #     resources :sales do
  #       get 'recent', :on => :collection
  #     end
  #   end

  # Sample resource route within a namespace:
  #   namespace :admin do
  #     # Directs /admin/products/* to Admin::ProductsController
  #     # (app/controllers/admin/products_controller.rb)
  #     resources :products
  #   end

  # You can have the root of your site routed with "root"
  # just remember to delete public/index.html.
   root :to => "posts#index"

  # See how all your routes lay out with "rake routes"

  # This is a legacy wild controller route that's not recommended for RESTful applications.
  # Note: This route will make all actions in every controller accessible via GET requests.
  # match ':controller(/:action(/:id(.:format)))'
end
