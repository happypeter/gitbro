class PostsController < ApplicationController
  
  before_filter :init
  before_filter :check_perm, :only => [ :edit, :update, :destroy ]

  def check_perm
    if current_user == nil
      flash[:notice] = "Sorry, plz login first"
      redirect_to root_url
    end
  end
  
  def init
    require 'gollum'
    @wiki = Gollum::Wiki.new("/home/peter/ll/")
    
    @commit = { :message => 'no message',
               :name => 'No Name',
               :email => 'noname@example.com' }
    @commit[:name] = current_user.name if current_user
    @commit[:email] = current_user.email if current_user
  
  end
  # GET /posts
  # GET /posts.xml
  def index
    respond_to do |format|
      format.html # index.html.erb
      format.xml  { render :xml => @posts }
    end
  end

  # GET /posts/1
  # GET /posts/1.xml
  def show
    @page =  @wiki.page(params[:page_name])

    respond_to do |format|
      format.html # show.html.erb
      format.xml  { render :xml => @post }
    end
  end

  # GET /posts/new
  # GET /posts/new.xml
  def new
    respond_to do |format|
      format.html # new.html.erb
      format.xml  { render :xml => @post }
    end
  end

  # GET /posts/1/edit
  def edit
    @page =  @wiki.page(params[:page_name])
  end

  # POST /posts
  # POST /posts.xml
  def create
    @page = @wiki.page(params[:page_title])
    @commit[:message] = params[:commit_msg]
    @wiki.write_page(params[:page_title], :markdown, params[:page_content], @commit)
    respond_to do |format|
        format.html { redirect_to(root_url, :notice => 'successfully updated.') }
        format.xml  { head :ok }
    end
  end

  # PUT /posts/1
  # PUT /posts/1.xml
  def update
    @page = @wiki.page(params[:page_name])
    @wiki.update_page(@page,@page.name, @page.format, params[:page_content], @commit)
    respond_to do |format|
        format.html { redirect_to(root_url, :notice => 'successfully updated.') }
        format.xml  { head :ok }
    end
  end

  # DELETE /posts/1
  # DELETE /posts/1.xml
  def destroy

    respond_to do |format|
      format.html { redirect_to(posts_url) }
      format.xml  { head :ok }
    end
  end
end
